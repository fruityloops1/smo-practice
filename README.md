# SMO Practice Mod

This is a mod for Super Mario Odyssey that adds different features that intend to aid in speedrun practice (but can also be used for other reasons).

The mod is compatible with versions 1.0.0 and 1.3.0 of Super Mario Odyssey. Note that the 1.3.0 version does not yet support the TAS script player.

This is a continuation of the [original version of this mod by fruityloops1](https://github.com/fruityloops1/smo-practice).

## Features

- Teleporting (position saving and restoring).
- Moon refreshing (collect the same moon multiple times without reloading).
- Turn autosaving on/off.
- Stage warping.
- Info display (player position, velocity, speed, etc.).
- TAS Script Player (v1.0.0 only).
- Other small features.

## Prerequisites

- [devkitPro](https://devkitpro.org/).
- [Python 3](https://www.python.org/).
- The [Keystone](https://www.keystone-engine.org/) Python module.

## Building

By default, the mod is compiled for the SMO version 1.3.0. To compile for 1.0.0, you can set
```
S2VER ?= 100
S2VERSTR ?= 1.0.0
```
in Makefile. Alternatively, you can follow platform-specific instructions below.

Build has been tested on Arch Linux and Windows 10.

### Arch Linux

Just run:

```
DEVKITPRO={path_to_devkitpro} make
```

devkitPro will be installed to `/opt/devkitpro` on most Unix-based systems. To compile for 1.0.0, run:

```
DEVKITPRO={path_to_devkitpro} make S2VER=100 S2VERSTR=1.0.0
```

### Windows

After setting the environment variables for devkitPro, just run:

```
make
```

To compile for 1.0.0, run:

```
make S2VER=100 S2VERSTR=1.0.0
```

## Building and Installing Through FTP

If you want to install the mod on your Switch through FTP immediately upon building, make sure you add the Switch's local IP address in Makefile, e.g.:

```
IP ?= 192.168.0.2
```

If necessary, the password and username for the FTP connection should be added to sendPatch.py. Uncomment the following line (remove the #) and change the information accordingly:

```
#ftp.login(user="admin", passwd="admin")
```

Once this is set up, instead of `make`, run:

```
make send
```

## Installing

### Atmosphère

To install the prebuilt release version, copy the atmosphere folder to the root of your SD card.

If you have FTP set up on your Switch, see the previous section for instructions on how to send the files to your switch automatically upon building.

Alternatively, after running `make` to build it, you can transfer the files manually as detailed below.

For SMO version 1.0.0, transfer:

- `smo-practice100.nso` to `/atmosphere/contents/0100000000010000/exefs/subsdk1` (note: no extension).
- `starlight_patch_100/3CA12DFAAF9C82DA064D1698DF79CDA1.ips` to `/atmosphere/exefs_patches/starlight_patch_100/3CA12DFAAF9C82DA064D1698DF79CDA1.ips`.
- `romfs` to `/atmosphere/contents/0100000000010000/romfs`.

For SMO version 1.3.0, transfer:

- `smo-practice130.nso` to `/atmosphere/contents/0100000000010000/exefs/subsdk1` (note: no extension).
- `starlight_patch_130/B424BE150A8E7D78701CBE7A439D9EBF.ips` to `/atmosphere/exefs_patches/starlight_patch_130/B424BE150A8E7D78701CBE7A439D9EBF.ips`.
- `romfs` to `/atmosphere/contents/0100000000010000/romfs`.

### Yuzu

First open the Yuzu `Mod Data Location` for SMO. It can be opened by right-clicking on the game in Yuzu (alternatively `%YUZU_DIR%/load/0100000000010000`). Then make a new folder for the practice mod and transfer the following files into the newly created folder:
- `smo-practice100.nso` to `<new-folder>/exefs/subsdk1` (note: no extension).
- `starlight_patch_100/3CA12DFAAF9C82DA064D1698DF79CDA1.ips` to `<new-folder>/exefs/3CA12DFAAF9C82DA064D1698DF79CDA1.ips`.
- `romfs` to `<new-folder>/romfs`.

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

For SMO version 1.3.0, transfer `smo-practice130.nso` and `starlight_patch_130/B424BE150A8E7D78701CBE7A439D9EBF.ips` instead.

For more information, check out Yuzu's [official help page for game modding](https://yuzu-emu.org/help/feature/game-modding/).

## Building TAS Server (v1.0.0)

Build has only been tested on Arch Linux. CMake is required.

```
cd smo-tas-server
mkdir build && cd build
cmake ..
make
```

## Credits
- [Fruityloops](https://github.com/fruityloops1), for the [earlier versions of this mod](https://github.com/fruityloops1/smo-practice).
- [CraftyBoss](https://github.com/CraftyBoss), for his [work on TextWriter](https://github.com/CraftyBoss/Starlight-SMO-LayoutEditing).
- [bryce_____](https://github.com/brycewithfiveunderscores), for his [Starlight SMO example](https://github.com/brycewithfiveunderscores/Starlight-SMO-Example).
- devkitA64.
- [libnx](https://github.com/switchbrew/libnx), for the Switch build rules.