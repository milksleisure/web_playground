#!/bin/bash
HOST=$1
export FLASK_APP=quick_start.py; flask run --host=$HOST
