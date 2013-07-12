@cd library
7z a -tzip ..\library.zip * -xr!ndll\obj -xr!ndll\*.depend -xr!ndll\*.layout
@cd ..
