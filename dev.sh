#!/bin/bash

# c++26

DEBUG='make && ./C++' \
CC=clang CXX=clang CXXFLAGS='-fno-elide-constructors -std=c++11' PATH="${XDG_DATA_HOME:-$HOME/.local/share}/nvim/python-venv/bin:$PATH" \
    nvim -S Session.vim
