# Starlight — SMO Example

This repo contains a barebones example of a Super Mario Odyssey v1.0.0 mod written (for the most part) in C++.
It is a fork of [Starlight](https://github.com/shadowninja108/Starlight), an awesome project geared toward mod creation for Splatoon 2.

The mod itself is the same as the one in [Responding to Controller Inputs in Super Mario Odyssey](https://brycewithfiveunderscores.com/posts/accessing-controls/) (teleport Mario to y=0 on Left D-Pad press), so as to act as a good comparison between an assembly-based implementation and a C++ one.

The changes in this fork are made incrementally & intentionally, with the goal of being a working example of what specifically needs to be updated in Starlight in order to adapt it to other games. You can see the required steps in the form of
[Pull Requests](https://github.com/brycewithfiveunderscores/Starlight-SMO-Example/pulls?q=label%3Ainitial-change+sort%3Acreated-asc), each of which has a description of the change, and occasionally code review comments describing specific details.

## Prerequisites

- [devkitPro](https://devkitpro.org/) 
- Python 3
- The [Keystone-Engine](https://www.keystone-engine.org/) Python Module

## Building

Build has only been tested on WSL2 running Ubuntu 20.04.1.

Just run:
```
DEVKITPRO={path_to_devkitpro} make
```

On Ubuntu (and other Debian-based systems), devkitPro will be installed to `/opt/devkitpro` by default:

```
DEVKITPRO=/opt/devkitpro/ make
```

## Installing (Atmosphère)

After a successful build, transfer:

- `Starlight-SMO-Example100.nso` to `/atmosphere/contents/0100000000010000/exefs/subsdk1` (note: no extension)
- `starlight_patch_100/3CA12DFAAF9C82DA064D1698DF79CDA1.ips` to `/atmosphere/exefs_patches/starlight_patch_100/3CA12DFAAF9C82DA064D1698DF79CDA1.ips`

---

# Starlight (Original README)
An enviroment for linking to Splatoon 2 executable and implementing hooks.

# Contributors
- [3096](https://github.com/3096)
- [khang06](https://github.com/khang06)
- [OatmealDome](https://github.com/OatmealDome)
- [Random0666](https://github.com/random0666)
- [shadowninja108](https://github.com/shadowninja108)
- [shibbo](https://github.com/shibbo) - Repo based on their work on OdysseyReversed
- [Thog](https://github.com/Thog) - Expertise in how rtld is implemented

# Credits
- devkitA64
- libnx - switch build rules
