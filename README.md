Note: Much, if not all of what is described below is yet to be implemented.

# T9 distrubtion build system

T9 is an experimental software distribution build kit based upon T2 SDE
(https://t2sde.org) and inspired by Plan 9 philosophy. Some of the features
implemented as part of it may be partially or completely implemented in upstream
in the future. 

Among the ideas for experiments are:
- replacing complex software with simpler equivalents
- reducing the amount of C code by replacing it with code in safer languages
(Go, Rust)
- smarter optimization on various platforms (e.g. IA-64)
- better package build speed
- more flexible and optimized build system
- and more

**T9 is for experimenting only, it's not meant to be used as a daily driver. If
you're looking for a distribution to install and use, see T2 SDE above.**

## Structure

The core of T9 is its build system, contained in this repository. Additionally
T9 uses package definitions from upstream T2 SDE SVN/Git, these are separate
from the rest.

There are two flavors of T9, represented by two different targets:
- *generic* target, aiming to stay close to T2 generic target
- *t9* target, a Plan 9-inspired flavor with the goal of testing new OS concepts

If you wish to use T9 as a regular Linux distribution, we recommend you use the
generic target.

## t9 target

t9 target replaces many of standard GNU utilities with either their alternatives
from Plan 9 or more modern replacements written in a different language than C.
To avoid breaking GNU compatibility, GNU versions of the replaced utilities are
available with the `g` prefix.
