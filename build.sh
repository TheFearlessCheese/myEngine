#!/bin/bash
echo Building Library...

ar rcs libmyEngine.a *.o

rm -f *.o