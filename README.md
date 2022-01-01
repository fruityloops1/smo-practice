# Practice Mod

This is a mod for Super Mario Odyssey that adds different features that intend to aid in speedrun practice (but can also be used for other reasons)
### Features
- Position saving and restoring
- Moon refreshing
- Toggle Autosaving on/off
- Stage warping
- Info display (player position, velocity, speed, etc.)
- TAS Script Player
- Other small features

## Prerequisites

- [devkitPro](https://devkitpro.org/) 
- Python 3
- The [Keystone-Engine](https://www.keystone-engine.org/) Python Module

## Building

Build has only been tested on Arch Linux

Just run:
```
DEVKITPRO={path_to_devkitpro} make
```
devkitPro will be installed to `/opt/devkitpro` on most Unix-based systems

By default, the mod is compiled for the SMO `1.0.0` version. 
To compile for the `1.3.0` version, you can run the following command.

```
DEVKITPRO={path_to_devkitpro} make S2VER=130 S2VERSTR=1.3.0
```

## Installing (Atmosphère)

After a successful build, transfer:

For the SMO version `1.0.0`,

- `smo-practice100.nso` to `/atmosphere/contents/0100000000010000/exefs/subsdk1` (note: no extension)
- `starlight_patch_100/3CA12DFAAF9C82DA064D1698DF79CDA1.ips` to `/atmosphere/exefs_patches/starlight_patch_100/3CA12DFAAF9C82DA064D1698DF79CDA1.ips`
- `romfs` to `/atmosphere/contents/0100000000010000/romfs`

For the SMO version `1.3.0`,

- `smo-practice130.nso` to `/atmosphere/contents/0100000000010000/exefs/subsdk1` (note: no extension)
- `starlight_patch_130/B424BE150A8E7D78701CBE7A439D9EBF.ips` to `/atmosphere/exefs_patches/starlight_patch_130/B424BE150A8E7D78701CBE7A439D9EBF.ips`
- `romfs` to `/atmosphere/contents/0100000000010000/romfs`

## Install (Yuzu)

First open the Yuzu `Mod Data Location` for SMO. 
It can be opened by right-clicking on the game in yuzu (alternatively `%YUZU_DIR%/load/0100000000010000`). 
Then make a new folder for the practice mod and transfer the following files into the newly created folder.
- `smo-practice100.nso` to `<new-folder>/exefs/subsdk1` (note: no extension)
- `starlight_patch_100/3CA12DFAAF9C82DA064D1698DF79CDA1.ips` to `<new-folder>/exefs/3CA12DFAAF9C82DA064D1698DF79CDA1.ips`
- `romfs` to `<new-folder>/romfs`

After the file transfer, the new folder should have the following structure,

```
├── <new-folder-name>
│   ├── exefs
│   │   ├── 3CA12DFAAF9C82DA064D1698DF79CDA1.ips
│   │   └── subsdk1  <-- smo-practice100.nso
│   └── romfs
│       ├── DebugData
│       │   └── ...
│       └── LayoutData
│           └── ...
```

For SMO version `1.3.0`, transfer the `smo-practice130.nso` and `starlight_patch_130/B424BE150A8E7D78701CBE7A439D9EBF.ips` instead.

For more information, check out the Yuzu's [official help page for game modding](https://yuzu-emu.org/help/feature/game-modding/).

## Building TAS Server

Build has only been tested on Arch Linux, CMake is required

```
cd smo-tas-server
mkdir build && cd build
cmake ..
make
```

# Credits
- CraftyBoss - [work on TextWriter](https://github.com/CraftyBoss/Starlight-SMO-LayoutEditing)
- bryce_____ - [Example](https://github.com/brycewithfiveunderscores/Starlight-SMO-Example)
- devkitA64
- libnx - switch build rules