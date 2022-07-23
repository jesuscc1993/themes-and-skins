[Metadata]
Version = 1.0.0
Description = Displays the current time
Author = MetalTxus
License = Creative Commons BY-NC 3.0

[Rainmeter]
Group = HotkeyToggle

[Variables]
FontFace = Segoe UI
; %H:%M:%S
TimeFormat = %H:%M
OpenDateAndTime = [Shell:::{E2E7934B-DCE5-43C4-9576-7FE4F75E7480}]

[MeasureTime]
Measure = Time
Format = #TimeFormat#

[BackgroundImage]
Meter = Image
SolidColor = 0, 0, 0, 1
W = #Width#
H = #Height#
LeftMouseUpAction = #OpenDateAndTime#

[StringTime]
Meter = String
MeasureName = MeasureTime
AntiAlias = 1
FontColor = 255, 255, 255, 255
FontEffectColor = 0, 0, 0, 64
FontFace = #FontFace#
FontSize = #FontSize#
FontWeight = #FontWeight#
InlineSetting = Shadow | 0 | 0 | 2 | 0, 0, 0, 255
InlineSetting2 = Shadow | 0 | 0 | 1 | 0, 0, 0, 128
StringAlign = CenterCenter
StringEffect = Border
W = #Width#
H = #Height#
X = #HalfWidth#
Y = #HalfHeight#
;Text = 00:00