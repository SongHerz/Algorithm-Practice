#!/usr/bin/env python

import sys
import subprocess as sp
import showheap

def showHeap( msg):
    assert msg.startswith("HEAP:")
    heap = msg.split()[1:]
    aHeap = showheap.Heap( heap)
    aHeap.show()

def dispatchMsg( msg):
    sys.stdout.write( msg)
    if msg.startswith("HEAP:"):
        showHeap( msg)
        

def main():
    p = sp.Popen("./test", stdout = sp.PIPE)
    while p.poll() is None:
        stdout, stderr = p.communicate()
        lines = stdout.splitlines( True)
        for eachLine in lines:
            dispatchMsg( eachLine)

    pass


main()
