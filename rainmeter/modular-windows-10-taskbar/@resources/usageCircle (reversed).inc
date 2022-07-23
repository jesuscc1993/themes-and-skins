[Rainmeter]
Update = 1000
LeftMouseUpAction = #OnClick#

[Variables]
@IncludeColors = #@#colors.inc
@IncludeStyles = #@#styles.inc
warningLevel = 70
dangerLevel = 90

[MeterBackground]
Meter = Image
SolidColor = #cTransparent#
LeftMouseUpAction = #OnClick#
W = 92
H = 40

[UsageCircleBackImpl]
Meter = Roundline
MeterStyle = UsageCircle
LineColor = #cDarkGray#
X = 54
Y = 2
W = 36
H = 36

[UsageCircleImpl]
Meter = Roundline
MeterStyle = UsageCircle
MeasureName = #CircleMeasure#
LineColor = #cWhite#
X = 54
Y = 2
W = 36
H = 36

[UsagePercentImpl]
Meter = String
MeterStyle = UsageCirclePercent
MeasureName = #CircleMeasure#
X = 73
Y = 20

[UsageLabelImpl]
Meter = String
MeterStyle = UsageCircleLabel
Text = #CircleLabel#
X = 0
Y = 10

[DummyColoringMeasure]
Measure = CPU
IfCondition = #CircleMeasure# <= #warningLevel#
IfTrueAction = [!SetOption UsageCircleImpl LineColor "#cWhite#"][!UpdateMeter UsageCircleImpl][!Redraw]
IfCondition2 = (#CircleMeasure# > #warningLevel#) && (#CircleMeasure# <= #dangerLevel#)
IfTrueAction2 = [!SetOption UsageCircleImpl LineColor "#cOrange#"][!UpdateMeter UsageCircleImpl][!Redraw]
IfCondition3 = #CircleMeasure# > #dangerLevel#
IfTrueAction3 = [!SetOption UsageCircleImpl LineColor "#cRed#"][!UpdateMeter UsageCircleImpl][!Redraw]