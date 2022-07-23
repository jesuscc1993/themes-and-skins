[Variables]
CircleMeasure = HDDPercentualMeasure
CircleLabel = #DriveLetter#
OnClick = %SystemRoot%\explorer.exe "#DriveLetter#"
BytesInOneGygabyte = 1073741824

[MeterBackground]
Meter = Image
SolidColor = #cTransparent#
ToolTipTitle = Space left on #DriveLetter#
ToolTipType = 1
ToolTipIcon = Info
ToolTipText = [FormattedFreeHDDMeasure] GB / [FormattedTotalHDDMeasure] GB
ToolTipEnabled = 1
DynamicVariables = 1
W = 80
H = 40

[TotalHDDMeasure]
Measure = FreeDiskSpace
Drive = #DriveLetter#
IgnoreRemovable = 0
Total = 1

[FormattedTotalHDDMeasure]
Measure = Calc
Formula = Round(TotalHDDMeasure / #BytesInOneGygabyte#, 1)

[UsedHDDMeasure]
Measure = FreeDiskSpace
Drive = #DriveLetter#
IgnoreRemovable = 0
InvertMeasure = 1

[FreeHDDMeasure]
Measure = FreeDiskSpace
Drive = #DriveLetter#
IgnoreRemovable = 0

[FormattedFreeHDDMeasure]
Measure = Calc
Formula = Round(FreeHDDMeasure / #BytesInOneGygabyte#, 1)

[HDDPercentualMeasure]
Measure = Calc
Formula = (UsedHDDMeasure * 100 / (TotalHDDMeasure))
MinValue = 0
MaxValue = 100

@IncludeStyles = #@#usageCircle (reversed).inc