for %%p in (A B C D E F G H I J K L M N O P Q R S T U V W X Y Z) do (
	mkdir %%p
	(
		echo [Metadata]
		echo Version = 1.0
		echo Description = Displays the current usage of the specified HDD
		echo Author = MetalTxus
		echo License = Creative Commons BY-NC 3.0
		echo.
		echo [Variables]
		echo DriveLetter = %%p:\
		echo.
		echo @IncludeStyles = #@#diskUsage.inc
	) > %%p/%%p.ini
)