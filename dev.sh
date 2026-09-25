#!/bin/bash

DEBUG='make && ./C++' \
CXXFLAGS='-fno-elide-constructors -std=c++2c' PATH="${XDG_DATA_HOME:-$HOME/.local/share}/nvim/python-venv/bin:$PATH" \
    nvim -S Session.vim
