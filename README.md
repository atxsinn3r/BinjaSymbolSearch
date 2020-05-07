# Binary Ninja Regex Symbol Search

## Description

This is a Binary Ninja plugin written in C++ for the Mac OS platform that allows you to search
for symbols based on a regular expression pattern. The results will be printed in the log view,
and clicking on them will take you where the code is.

As of now, Binary Ninja does not have this functionality built in, but naturally they should,
so it's probably a matter of time. Instead of submitting this plugin to the community repo,
this serves more of an example of how to write a C++ plugin, because currently this isn't so
well documented.

To use this, simply drag the dylib file to the plugins folder, and then start Binary Ninja. You
will be able to find it under the Tools option.

