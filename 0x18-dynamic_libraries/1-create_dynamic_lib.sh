#!/bin/bash
gcc -shared -o liball.so *.o
ar rc liball.so *.o
