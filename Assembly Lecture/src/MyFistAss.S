;My Assemply File
;R21 has param 1
;R22 has param 2
;return R24

.global MyAssemblyAdd       //exposes function so that it cam be called
.global TurnOnLED
.global TurnOffLED
.global YesTheresAnA
MyAssemblyAdd:
add R24, R22
ret

TurnOnLED:
sbi 8, 7
ret

TurnOffLED:
cbi 8, 7
ret

YesTheresAnA:
ldi R16,0
ldi R17, 65
movw R26, R24
loopagain:
ld R7, X+
cp R7, R17
breq foundit
cp R16,R7
brne loopagain
ldi R24, 0
ret
foundit:
ldi R24, 1
ret