## PCB Component Placement

This section documents the component placement stage of the
Smart Irrigation System PCB before routing.

The objective of this step was to ensure logical grouping of
components, short signal paths, and easy accessibility of
connectors and buttons.

---

## Placement Strategy

- ESP32 module placed near the center of the board to minimize
  routing length to peripherals.
- USB connector placed at the board edge for easy access.
- Programming buttons (EN and IO0) placed close to ESP32.
- Power regulation components grouped together to reduce noise.
- Sensor and LCD headers aligned on one side for neat wiring.
- Decoupling capacitors placed close to their respective IC pins.

---

## Placement Iterations

- placement_initial.png  
  Shows the initial arrangement of components after importing
  the schematic into the PCB editor.

- placement_final.png  
  Shows the optimized component placement used before routing,
  ensuring better signal flow and manufacturability.

This finalized placement served as the base for PCB routing.
