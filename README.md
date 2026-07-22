# Keyboards

This repository contains the configurations for my QMK and Kanata keyboards. Currently, it includes only QMK keyboard layouts, but over time, it will be updated to feature all my configurations, including home-row mods, special mod-taps, and other customizations.

## QMK

### How to use it?

First, you need to symlink your custom keyboards into the `qmk_firmware` directory. This repository isn't a `qmk_userspace`; instead, it is a place to manage custom keyboards directly within the original QMK structure.

```terminal
ln -s $HOME/Projects/keyboards/qmk/keyboards/* $QMK_HOME/keyboards/
ln -s $HOME/Projets/keyboards/qmk/users/* $QMK_HOME/users/
```

Later, you just make a firmware directly into the `qmk_firmware` folder.

```terminal
qmk compile -kb rk/r75/iso -km henrique
```

## License

This repository is licensed under the [GNU General Public License 2.0 or later](./LICENSE).

