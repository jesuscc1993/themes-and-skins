[Variables]
DigitRegex="^([0-9]{1})([0-9]{1})([0-9]{1})([0-9]{1})([0-9]{1})([0-9]{1})([0-9]{1})([0-9]{1})$"
DigitHeight=19
DigitWidth=13
SeparatorWidth=7
ImageHeight=19
ImageSpacing=-2

[MeasureDate]
Measure=Time
Format=%Y%m%d

[MeasureYear1]
Measure=String
String=[MeasureDate]
DynamicVariables=1
RegExpSubstitute=1
Substitute="#DigitRegex#":"\1"

[MeasureYear2]
Measure=String
String=[MeasureDate]
DynamicVariables=1
RegExpSubstitute=1
Substitute="#DigitRegex#":"\2"

[MeasureYear3]
Measure=String
String=[MeasureDate]
DynamicVariables=1
RegExpSubstitute=1
Substitute="#DigitRegex#":"\3"

[MeasureYear4]
Measure=String
String=[MeasureDate]
DynamicVariables=1
RegExpSubstitute=1
Substitute="#DigitRegex#":"\4"

[MeasureMonth1]
Measure=String
String=[MeasureDate]
DynamicVariables=1
RegExpSubstitute=1
Substitute="#DigitRegex#":"\5"

[MeasureMonth2]
Measure=String
String=[MeasureDate]
DynamicVariables=1
RegExpSubstitute=1
Substitute="#DigitRegex#":"\6"

[MeasureDay1]
Measure=String
String=[MeasureDate]
DynamicVariables=1
RegExpSubstitute=1
Substitute="#DigitRegex#":"\7"

[MeasureDay2]
Measure=String
String=[MeasureDate]
DynamicVariables=1
RegExpSubstitute=1
Substitute="#DigitRegex#":"\8"

[ImageYear1]
Meter=Image
MeasureName=MeasureYear1
ImagePath=#ImagePath#
W=#DigitWidth#
H=#DigitHeight#

[ImageYear2]
Meter=Image
MeasureName=MeasureYear2
ImagePath=#ImagePath#
W=#DigitWidth#
H=#DigitHeight#
X=#ImageSpacing#R

[ImageYear3]
Meter=Image
MeasureName=MeasureYear3
ImagePath=#ImagePath#
W=#DigitWidth#
H=#DigitHeight#
X=#ImageSpacing#R

[ImageYear4]
Meter=Image
MeasureName=MeasureYear4
ImagePath=#ImagePath#
W=#DigitWidth#
H=#DigitHeight#
X=#ImageSpacing#R

[ImageYearSeparator]
Meter=Image
ImageName=separator_date.png
ImagePath=#ImagePath#
W=#SeparatorWidth#
H=#ImageHeight#
X=#ImageSpacing#R

[ImageMonth1]
Meter=Image
MeasureName=MeasureMonth1
ImagePath=#ImagePath#
W=#DigitWidth#
H=#DigitHeight#
X=#ImageSpacing#R

[ImageMonth2]
Meter=Image
MeasureName=MeasureMonth2
ImagePath=#ImagePath#
W=#DigitWidth#
H=#DigitHeight#
X=#ImageSpacing#R

[ImageMonthSeparator]
Meter=Image
ImageName=separator_date.png
ImagePath=#ImagePath#
W=#SeparatorWidth#
H=#ImageHeight#
X=#ImageSpacing#R

[ImageDay1]
Meter=Image
MeasureName=MeasureDay1
ImagePath=#ImagePath#
W=#DigitWidth#
H=#DigitHeight#
X=#ImageSpacing#R

[ImageDay2]
Meter=Image
MeasureName=MeasureDay2
ImagePath=#ImagePath#
W=#DigitWidth#
H=#DigitHeight#
X=#ImageSpacing#R