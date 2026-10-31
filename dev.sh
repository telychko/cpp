#!/bin/bash

#std="c++11"
std="c++26"

#CC=clang CXX=clang \
DEBUG='make && ./C++' \
CXXFLAGS="-std=$std -fno-elide-constructors" PATH="${XDG_DATA_HOME:-$HOME/.local/share}/nvim/python-venv/bin:$PATH" \
    nvim -S Session.vim
