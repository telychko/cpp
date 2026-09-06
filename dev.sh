#!/bin/bash

DEBUG='make && ./C++' \
PATH="${XDG_DATA_HOME:-$HOME/.local/share}/nvim/python-venv/bin:$PATH" \
    nvim -S Session.vim
