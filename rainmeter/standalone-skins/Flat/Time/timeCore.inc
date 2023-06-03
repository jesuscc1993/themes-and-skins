[Metadata]
Version = 1.0.0
Description = Displays the current time
Author = MetalTxus
License = Creative Commons BY-NC 3.0

[Rainmeter]
Group = HotkeyToggle

[Variables]
; TimeFormat = %H:%M
AntiAlias = 1
FontColor = 255, 255, 255, 255
FontEffectColor = 0, 0, 0, 64
FontFace = Segoe UI
FontWeight = 400
InlineSetting = Shadow | 0 | 0 | 1 | 0, 0, 0, 255
InlineSetting2 = Shadow | 0 | 0 | 2 | 0, 0, 0, 128
OpenDateAndTime = [Shell:::{E2E7934B-DCE5-43C4-9576-7FE4F75E7480}]
StringAlign = CenterCenter
StringEffect = Border
TimeFormat = %H:%M

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
AntiAlias = #AntiAlias#
FontColor = #FontColor#
FontEffectColor = #FontEffectColor#
FontFace = #FontFace#
FontSize = #FontSize#
FontWeight = #FontWeight#
InlineSetting = #InlineSetting#
InlineSetting2 = #InlineSetting2#
InlineSetting3 = #InlineSetting3#
InlineSetting4 = #InlineSetting4#
InlineSetting5 = #InlineSetting5#
InlineSetting6 = #InlineSetting6#
InlineSetting7 = #InlineSetting7#
InlineSetting8 = #InlineSetting8#
StringAlign = #StringAlign#
StringEffect = #StringEffect#
W = #Width#
H = #Height#
X = #TextX#
Y = #TextY#
;Text = 08:08