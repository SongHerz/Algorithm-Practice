#!/usr/bin/env python

import pygraphviz as pgv

class Heap:
    def __init__( self, heap):
        self.heap = heap
        self.G = self._createGraph()

    @staticmethod
    def _leftIdx( parentIdx):
            return parentIdx * 2 + 1


    @staticmethod
    def _rightIdx( parentIdx):
            return parentIdx * 2 + 2

    def _isValidIdx( self, idx):
        return idx < len( self.heap)

    def _createGraph( self):
        G = pgv.AGraph( strict = False, directed = False)
        idx = 0
        while True:
            left = self._leftIdx( idx)
            if self._isValidIdx( left):
                G.add_edge( self.heap[ idx], self.heap[ left]);
            else:
                break

            right = self._rightIdx( idx)
            if self._isValidIdx( right):
                G.add_edge( self.heap[ idx], self.heap[ right]);
            else:
                break

            idx += 1

        if len( G.nodes()) == 0:
            assert len( self.heap) <= 1
            if len( self.heap) == 1:
                G.add_node( self.heap[ 0])

        return G

    def show( self):
        try:
            self.G.draw( format = 'xlib', prog = 'dot')
        except IOError as why:
            print "IOError:", why.errno, why.filename, why.args
        pass



if __name__ == "__main__":
    heap0 = [];
    heap1 = ['a'];
    heap2 = ['a', 'b', 'c'];
    heap3 = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h']

    aHeap0 = Heap( heap0);
    aHeap1 = Heap( heap1);
    aHeap2 = Heap( heap2);
    aHeap3 = Heap( heap3);
    aHeap0.show();
    aHeap1.show();
    aHeap2.show();
    aHeap3.show();
