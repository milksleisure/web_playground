#!/usr/bin/env python
from flask import Flask
from subprocess import call
app = Flask(__name__)

@app.route('/')
def hello_world():
    return 'Hello, World!'

