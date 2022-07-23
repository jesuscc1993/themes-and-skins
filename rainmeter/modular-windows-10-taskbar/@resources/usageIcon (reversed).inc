[Rainmeter]
Update = 1000

[Variables]
@IncludeColors = #@#colors.inc
@IncludeStyles = #@#styles.inc

[MeasureImpl]
Measure = #ValueMeasure#
MeterStyle = MeasureImplStyle

[MeterBackground]
Meter = Image
SolidColor = #cTransparent#
W = 108
H = 40

[UsageValueImpl]
Meter = String
NumOfDecimals = 1
MeasureName = MeasureImpl
MeterStyle = UsageValueLabel
Scale=1048576 ; 1024*1024
;Text="000.0 MB/s"
Text="%1 MB/s"
X = 76
Y = 21

[UsageIconImpl]
Meter = Image
ImageName = #ValueIcon#
X = 4
Y = 8