#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "elist.h"

struct my_node {
    int val;
    struct list_head head;
};

LIST_HEAD( busy_que);
LIST_HEAD( idle_que);


void init_que( struct list_head *busy_que, struct list_head *idle_que) {
    int i;
    for ( i = 0; i < 10; ++i) {
        struct my_node *n = malloc( sizeof( *n));
        n->val = i;
        INIT_LIST_HEAD( &n->head);
        list_add_tail( &n->head, idle_que);
    }
}


void _destroy_a_que( struct list_head *que) {
    struct list_head *pos, *n;
    list_for_each_safe( pos, n, que) {
        struct my_node *n = list_entry( pos, struct my_node, head);
        list_del( pos);
        free( n);
    }
}

void destroy_que( struct list_head *busy_que, struct list_head *idle_que) {
    _destroy_a_que( busy_que);
    _destroy_a_que( idle_que);
}


void _show_list( const struct list_head *que, const char *prefix) {
    struct list_head *pos;

    assert( prefix);
    printf("%s:", prefix);

    list_for_each( pos, que) {
        const struct my_node *n = list_entry( pos, struct my_node, head);
        printf(" %d", n->val);
    }
    printf("\n");
}


void show_lists( const struct list_head *busy_que, struct list_head *idle_que) {
    _show_list( busy_que, "Busy Queue");
    _show_list( idle_que, "Idle Queue");
}


void bar( const char c, size_t l) {
    size_t i;
    for ( i = 0; i < l; ++i) {
        putchar( c);
    }
    putchar('\n');
}


void title(const char *t) {
    const size_t l = strlen( t);
    bar( '=', l);
    puts( t);
    bar( '=', l);
}


void random_move( struct list_head *from, struct list_head *to, int ratio) {
    struct list_head *pos, *n;
    int i;
    list_for_each_safe( pos, n, from) {
        if ( random() % ratio == 0) {
            struct my_node *n = list_entry( pos, struct my_node, head);
            printf("Move %d to the tail of another queue\n", n->val);
            list_move_tail( pos, to);
        }
        i++;
    }
}

int main() {
    init_que( &busy_que, &idle_que);
    title("After initialization");
    show_lists( &busy_que, &idle_que);

    title("Begin to move nodes from idle_que to busy_que");
    random_move( &idle_que, &busy_que, 3);
    show_lists( &busy_que, &idle_que);

    title("Begin to move nodes from busy_que to idle_que");
    random_move( &busy_que, &idle_que, 2);
    show_lists( &busy_que, &idle_que);

    destroy_que( &busy_que, &idle_que);
    title("After destroy");
    show_lists( &busy_que, &idle_que);

    return 0;
}
