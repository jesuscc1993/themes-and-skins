[Metadata]
Version = 1.0.0
Description = Recycle Bin icon with custom contextual menu
Author = MetalTxus
License = Creative Commons BY-NC 3.0

[Rainmeter]
Update = 1000
ContextTitle = Open Recycle Bin
ContextAction = [!CommandMeasure MeasureCount "OpenBin"]
ContextTitle2 = Empty Recycle Bin
ContextAction2 = [!CommandMeasure MeasureCount "EmptyBin"]
ContextTitle3 = ----
ContextTitle4 = [MeasureCount] file(s), [MeasureFormattedSize] [MeasureSizeUnit]
ContextAction4 = []
ContextTitle5 = ----
ContextTitle6 = Skin settings
ContextAction6 = [!SkinMenu]

LeftMouseUpAction = [!CommandMeasure MeasureCount "OpenBin"]
RightMouseUpAction = [!SkinCustomMenu]

[MeasureCount]
Measure = Plugin
Plugin = RecycleManager.dll
RecycleType = Count

IfBelowValue = 1
IfBelowAction = [!SetOption ImageTrash ImageName "#@#icons/Recycle Bin (empty).png"][!UpdateMeter ImageTrash][!Redraw]
IfAboveValue = 0
IfAboveAction = [!SetOption ImageTrash ImageName "#@#icons/Recycle Bin (full).png"][!UpdateMeter ImageTrash][!Redraw]

[MeasureSize]
Measure = Plugin
Plugin = RecycleManager.dll
RecycleType = Size

[MeasureFormattedSize]
Measure = Calc
Formula = ((( MeasureSize / ( 1024 ** 3 )) >= 1 ) ? ( Round ( MeasureSize / ( 1024 ** 3 ),1)) : ((( MeasureSize / ( 1024 ** 2 )) >= 1 ) ? ( Round ( MeasureSize / ( 1024 ** 2 ),1)) : ((( MeasureSize / 1024 ) >= 1 ) ? ( Round ( MeasureSize / 1024,1 )) : MeasureSize )))

[MeasureSizeUnit]
Measure = Calc
Formula = ((( MeasureSize / ( 1024 ** 3 )) >= 1 ) ? 3 : ((( MeasureSize / ( 1024 ** 2 )) >= 1 ) ? 2 : ((( MeasureSize / 1024 ) >= 1 ) ? 1 : 0 )))
Substitute = "0":"B", "1":"kB", "2":"MB", "3":"GB"