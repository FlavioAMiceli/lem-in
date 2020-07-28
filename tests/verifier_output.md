# verifier output

## output errors

$> ./lem-in tests/maps/valid_super_3 | ./verifier
74

$> ./lem-in tests/maps/valid_super_10 | ./verifier
72

$> ./lem-in tests/maps/valid_big_2 | ./verifier
83

$> ./lem-in tests/maps/hard1.map | ./verifier
~~~~~~~~~~~~ inf loop ~~~~~~~~~~~~~

$> ./lem-in tests/maps/hard3.map | ./verifier
ERROR at line 8672: ant 13 moves to an occupied room
L2-Hub3 L3-Qhy2 L4-Tc_6 L5-Ubq7 L6-Oep6 L7-Dbs9 L8-Hzt6 L9-Yub5 L10-Ent8 L11-Wju2 L12-Jim1 L13-Qvb6 L14-Tre0 L15-Oio6 L16-Jal1 L17-Zqe6 L18-Bxk6 L19-Enh6 L20-Mg_9 L21-Zig3 L22-Uus4 L23-Sln2 L24-Xh_1

## correct output for different maps

### --flow-one

| input | steps required | our steps | comment |
| --- | --- | --- | --- |
| tests/maps/valid_flow_one_1 | 32 | 32 | perfect |
| tests/maps/valid_flow_one_2 | 27 | 27 | perfect |
| tests/maps/valid_flow_one_3 | 36 | 36 | perfect |
| tests/maps/valid_flow_one_4 | 36 | 36 | perfect |
| tests/maps/valid_flow_one_5 | 35 | 35 | perfect |
| tests/maps/valid_flow_one_6 | 32 | 32 | perfect |
| tests/maps/valid_flow_one_7 | 33 | 33 | perfect |
| tests/maps/valid_flow_one_8 | 31 | 31 | perfect |
| tests/maps/valid_flow_one_9 | 28 | 28 | perfect |
| tests/maps/valid_flow_one_10 | 32 | 32 | perfect |


### --flow-ten

| input | steps required | our steps | comment |
| --- | --- | --- | --- |
| tests/maps/valid_flow_ten_1 | 30 | 30 | perfect |
| tests/maps/valid_flow_ten_2 | 31 | 31 | perfect |
| tests/maps/valid_flow_ten_3 | 32 | 32 | perfect |
| tests/maps/valid_flow_ten_4 | 32 | 32 | perfect |
| tests/maps/valid_flow_ten_5 | 31 | 31 | perfect |
| tests/maps/valid_flow_ten_6 | 30 | 30 | perfect |
| tests/maps/valid_flow_ten_7 | 32 | 32 | perfect |
| tests/maps/valid_flow_ten_8 | 35 | 35 | perfect |
| tests/maps/valid_flow_ten_9 | 32 | 32 | perfect |
| tests/maps/valid_flow_ten_10 | 35 | 35 | perfect |


### --flow-thousand

| input | steps required | our steps | comment |
| --- | --- | --- | --- |
| tests/maps/valid_flow_thousand_1 | 30 | 30 | perfect |
| tests/maps/valid_flow_thousand_2 | 32 | 32 | perfect |
| tests/maps/valid_flow_thousand_3 | 28 | 28 | perfect |
| tests/maps/valid_flow_thousand_4 | 32 | 32 | perfect |
| tests/maps/valid_flow_thousand_5 | 30 | 30 | perfect |
| tests/maps/valid_flow_thousand_6 | 33 | 33 | perfect |
| tests/maps/valid_flow_thousand_7 | 31 | 31 | perfect |
| tests/maps/valid_flow_thousand_8 | 34 | 34 | perfect |
| tests/maps/valid_flow_thousand_9 | 29 | 29 | perfect |
| tests/maps/valid_flow_thousand_10 | 30 | 30 | perfect |


### --big

| input | steps required | our steps | comment |
| --- | --- | --- | --- |
| tests/maps/valid_big_1 | 53 | 53 | perfect |
| tests/maps/valid_big_2 | 65 | 65 | perfect |
| tests/maps/valid_big_3 | 100 | 101 | +1 |
| tests/maps/valid_big_4 | 78 | 79 | +1 |
| tests/maps/valid_big_5 | 64 | 65 | +1 |
| tests/maps/valid_big_6 | 53 | 54 | +1 |
| tests/maps/valid_big_7 | 77 | 82 | +5 |
| tests/maps/valid_big_8 | 77 | 77 | perfect |
| tests/maps/valid_big_9 | 46 | 46 | perfect |
| tests/maps/valid_big_10 | 66 | 66 | perfect |
| tests/maps/valid_big_11 | 67 | 68 | +1 |


### --big-superposition

| input | steps required | our steps | comment |
| --- | --- | --- | --- |
| tests/maps/valid_super_1 | 73 | 63 | -10 |
| tests/maps/valid_super_2 | 73 | 73 | perfect |
| tests/maps/valid_super_3 | 72 | 74 | +2 |
| tests/maps/valid_super_4 | 87 | 87 | perfect |
| tests/maps/valid_super_5 | 61 | 61 | perfect |
| tests/maps/valid_super_6 | 98 | 98 | perfect |
| tests/maps/valid_super_7 | 96 | 96 | perfect |
| tests/maps/valid_super_8 | 54 | 54 | perfect |
| tests/maps/valid_super_9 | 71 | 71 | perfect |
| tests/maps/valid_super_10 | 66 | 72 | +6 |
| tests/maps/valid_super_11 | 77 | 83 | +5 |
| tests/maps/hard1.map | 91 | 94 | +3 |
| tests/maps/hard2.map | 92 | 94 | +2 |
| tests/maps/hard3.map | 93 | 98 | +5 |
| tests/maps/hard4.map | 91 | 92 | +1 |
| tests/maps/hard5.map | 88 | 88 | perfect |
