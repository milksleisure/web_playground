#!/bin/bash
export FLASK_APP=flaskr
export FLASK_DEBUG=true

run () {
	flask run $*
}

initdb () {
	flask initdb
}
