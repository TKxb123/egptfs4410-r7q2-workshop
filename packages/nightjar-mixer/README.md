# Nightjar Eight-Channel Mixer - Design Package

Released design files for the Nightjar Eight-Channel Mixer, hardware revision Rev C. This package
accompanies the shipping product and is kept in sync with the current
production revision.

## Contents

- `hardware/` - bill of materials, netlist summary and assembly notes
- `firmware/` - board support and control firmware for the released revision
- `docs/` - calibration procedure and measured performance

## Implementation

The design is a two-board stack: a main board carrying the signal path and a
controller board carrying the MCU and the panel interface. The firmware in this
package targets the released Rev C controller board and is built with the
vendor toolchain at the pinned version recorded in `firmware/board.h`.

Production test fixtures and the calibration jig definition are described in
`docs/calibration.md`. The released package does not contain any deferred or
unreleased material.
