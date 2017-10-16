#!/bin/bash

set -e -u -o errexit -o errtrace

trap "echo ERROR!" ERR 

# trap a error (no func)
echo "Creating error."
false
