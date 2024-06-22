# Arduino/GRBL pin layout

| Pin | I/O    | Port | Default | GRBL standard        | Required | Modification | Notes                |
|-----|--------|------|---------|----------------------|----------|--------------|----------------------|
| 0   | SERCOM |      | RX      | Serial communication |          | -            | -                    |
| 1   | SERCOM |      | TX      | Serial communication |          | -            | -                    |
| 2   | D2     |      | D OUT   | Step pulse X         | Yes      | -            | -                    |
| 3   | D3     |      | D OUT   | Step pulse Y         | Yes      | -            | -                    |
| 4   | D4     |      | D OUT   | Step pulse Z         | Yes      | -            | -                    |
| 5   | D5     |      | D OUT   | Direction X          | Yes      | -            | -                    |
| 6   | D6     |      | D OUT   | Direction Y          | Yes      | -            | -                    |
| 7   | D7     |      | D OUT   | Direction Z          | Yes      | -            | -                    |
| 8   | D8     |      | D OUT   | Stepper enable       | Yes      | -            | -                    |
| 9   | D9     |      | D IN    | Limit X              | Yes      | -            | -                    |
| 10  | D10    |      | D IN    | Limit Y              | Yes      | -            | -                    |
| 11  | D11    |      | PWM     | Spindle speed        | No       | Limit Z      | -                    |
| 12  | D12    |      | D IN    | Limit Z              | Yes      | Abort ???    | -                    |
| 13  | D13    |      |         | Spindle direction    | Yes      | Motor ON     | -                    |
| 14  | A0/D14 | C 0  | D IN    | Abort                | Yes      | Feed rate 0  | Change to output pin |
| 15  | A1/D15 | C 1  | D IN    | Feed hold            | Maybe    | Feed rate 1  | Change to output pin |
| 16  | A2/D16 | C 2  | D IN    | Cycle start/Restart  | Maybe    | Feed rate 2  | Change to output pin |
| 17  | A3/D17 | C 4  | D OUT   | Coolant enable       | No       | Feed rate 3  | -                    |
| 18  | A4/D18 | C 5  | D OUT   | Mist coolant         | No       | Abort ???    | -                    |
| 19  | A5/D19 | C 6  | D IN    | Probe                | Maybe    | -            | Future update        |




