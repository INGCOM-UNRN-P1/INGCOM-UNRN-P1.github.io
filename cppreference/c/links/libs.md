From cppreference.com

< [c](../../c.html "c")‎ | [links](../links.html "c/links")

The objective of this page is to build a comprehensive list of open-source C libraries, so that when one needs an implementation of particular functionality, one needn’t to waste time searching on web ([DuckDuckGo](https://duckduckgo.com/), [Google](https://www.google.com/?gws_rd=ssl), [Bing](https://www.bing.com/), etc.) 

If you know a library that might be useful to others, please add a link to it here. There are no restrictions on what can be included except that the **source** of the library must be readily **available** to download. 

The page is provided “as is” - with the hope of being useful, but without any warranties. Outdated, misleading or wrong links might appear here. If you’ve noticed one of these, it would be great if you fixed the error. 

## Contents

  * [1 Package managers](libs.html#Package_managers)
  * [2 Libraries](libs.html#Libraries)
    * [2.1 Operating system](libs.html#Operating_system)
    * [2.2 Graphical user interface](libs.html#Graphical_user_interface)
    * [2.3 Gtk+ widgets](libs.html#Gtk.2B_widgets)
    * [2.4 Microsoft Excel](libs.html#Microsoft_Excel)
    * [2.5 Audio](libs.html#Audio)
    * [2.6 Video](libs.html#Video)
    * [2.7 Files](libs.html#Files)
    * [2.8 Maths](libs.html#Maths)
    * [2.9 Graphics](libs.html#Graphics)
    * [2.10 Generic](libs.html#Generic)
    * [2.11 Interprocess](libs.html#Interprocess)
    * [2.12 Databases](libs.html#Databases)
    * [2.13 Configuration](libs.html#Configuration)
    * [2.14 Environment](libs.html#Environment)
    * [2.15 Communications](libs.html#Communications)
    * [2.16 Compression](libs.html#Compression)
    * [2.17 Concurrency](libs.html#Concurrency)
    * [2.18 Data types](libs.html#Data_types)
    * [2.19 PDF](libs.html#PDF)
    * [2.20 XML](libs.html#XML)
    * [2.21 Metrics](libs.html#Metrics)
    * [2.22 Object oriented programming](libs.html#Object_oriented_programming)
    * [2.23 Web Frontend](libs.html#Web_Frontend)
    * [2.24 Debug](libs.html#Debug)
      * [2.24.1 See also](libs.html#See_also)
      * [2.24.2 External links](libs.html#External_links)

  
---  
  
# [[edit](https://en.cppreference.com/mwiki/index.php?title=c/links/libs&action=edit&section=1 "Edit section: Package managers")] Package managers

Package manager  |  Description   
---|---  
[build2](https://build2.org/) |  An open-source (MIT), cross-platform build toolchain that aims to approximate Rust Cargo’s convenience for developing and packaging C/C++ projects while providing more depth and flexibility, especially in the build system.   
[cget](https://cget.readthedocs.io/en/latest/) |  Cmake package retrieval. This can be used to download and install cmake packages.   
[cmodule](https://github.com/scapix-com/cmodule) |  Non-intrusive cmake dependency management.   
[conan](https://conan.io/) |  Decentralized, open-source (MIT), C/C++ package manager.   
[CPM.cmake](https://github.com/TheLartians/CPM.cmake) |  A cmake script that adds dependency management capabilities to cmake. It’s built as a thin wrapper around cmake’s FetchContent module that adds version control, caching, a simple API and more.   
[hunter](https://hunter.readthedocs.io/en/latest/) |  A cmake driven cross-platform package manager for C/C++ projects.   
[spack](https://spack.io) |  A package manager for supercomputers, Linux, and macOS. It makes installing scientific software easy. It isn’t tied to a particular language.   
[teaport](https://bitbucket.org/benman/teaport) |  A cocoapods inspired dependency manager.   
[vcpkg](https://docs.microsoft.com/en-us/cpp/vcpkg) |  A C/C++ package manager for Windows, Linux, and macOS.   
[xmake](https://xmake.io/) |  A cross-platform Lua-based C/C++ build tool and package manager.   
  
# [[edit](https://en.cppreference.com/mwiki/index.php?title=c/links/libs&action=edit&section=2 "Edit section: Libraries")] Libraries

## [[edit](https://en.cppreference.com/mwiki/index.php?title=c/links/libs&action=edit&section=3 "Edit section: Operating system")] Operating system

Access control 
Library  |  Description  |  License  |  Configuration   
---|---|---|---  
[acl](https://savannah.nongnu.org/projects/acl/) |  |  |   
[apparmor](https://apparmor.net/) |  |  |   
  
Extended attributes 
Library  |  Description  |  License  |  Configuration   
---|---|---|---  
[attr](https://savannah.nongnu.org/projects/attr/) |  |  |   
  
## [[edit](https://en.cppreference.com/mwiki/index.php?title=c/links/libs&action=edit&section=4 "Edit section: Graphical user interface")] Graphical user interface

Library  |  Description  |  License  |  Configuration   
---|---|---|---  
[IUP](http://www.tecgraf.puc-rio.br/iup/) |  |  |   
[Nuklear](https://github.com/Immediate-Mode-UI/Nuklear) |  A single-header ANSI C immediate mode cross-platform GUI library. ([Doc](https://immediate-mode-ui.github.io/Nuklear/doc/index.html))  |  |   
[lvgl](https://github.com/lvgl/lvgl) |  Powerful and easy-to-use embedded GUI library with many widgets, advanced visual effects (opacity, anti-aliasing, animations) and low memory requirements (16K RAM, 64K Flash). ([Doc](https://docs.lvgl.io/master/index.html))  |  |   
[tiny file dialogs](https://sourceforge.net/projects/tinyfiledialogs/) |  A single C cross-platform file (no init, no main loop, 6 modal function calls)  |  |   
  
## [[edit](https://en.cppreference.com/mwiki/index.php?title=c/links/libs&action=edit&section=5 "Edit section: Gtk+ widgets")] Gtk+ widgets

Library  |  Description  |  License  |  Configuration   
---|---|---|---  
[appmenu-gtk](https://launchpad.net/appmenu-gtk) |  |  |   
[ghex](https://wiki.gnome.org/Apps/Ghex) |  |  |   
[goocanvas](https://wiki.gnome.org/Projects/GooCanvas) |  |  |   
[gtkhotkey](https://launchpad.net/gtkhotkey) |  |  |   
[gtk+](https://www.gtk.org/) |  |  |   
[gtksourceview](https://wiki.gnome.org/Projects/GtkSourceView) |  |  |   
[gtkspell](https://gtkspell.sourceforge.net/) |  |  |   
[gucharmap](https://wiki.gnome.org/Apps/Gucharmap) |  |  |   
[webkitgtk](https://www.webkitgtk.org/) |  |  |   
  
## [[edit](https://en.cppreference.com/mwiki/index.php?title=c/links/libs&action=edit&section=6 "Edit section: Microsoft Excel")] Microsoft Excel

Library  |  Description  |  License  |  Configuration   
---|---|---|---  
[libxlsxwriter](https://libxlsxwriter.github.io/) |  |  |   
[xlsx_drone](https://github.com/damian-m-g/xlsx_drone) |  |  |   
  
## [[edit](https://en.cppreference.com/mwiki/index.php?title=c/links/libs&action=edit&section=7 "Edit section: Audio")] Audio

CD 
Library  |  Description  |  License  |  Configuration   
---|---|---|---  
[cdparanoia](https://www.xiph.org/paranoia/) |  |  |   
  
Codecs 
Library  |  Description  |  License  |  Configuration   
---|---|---|---  
[aften](http://aften.sourceforge.net/) |  |  |   
[faad2](http://www.audiocoding.com/) |  |  |   
[wavpack](http://www.wavpack.com) |  |  |   
  
Infrastructure 
Library  |  Description  |  License  |  Configuration   
---|---|---|---  
[alsa-lib](https://www.alsa-project.org/wiki/Main_Page) |  |  |   
[portaudio](http://www.portaudio.com/) |  |  |   
  
Speech synthesis 
Library  |  Description  |  License  |  Configuration   
---|---|---|---  
[espeak](http://espeak.sourceforge.net/) |  |  |   
[flite](http://www.festvox.org/flite/) |  |  |   
  
## [[edit](https://en.cppreference.com/mwiki/index.php?title=c/links/libs&action=edit&section=8 "Edit section: Video")] Video

Codecs 
Library  |  Description  |  License  |  Configuration   
---|---|---|---  
[schroedinger](https://slackbuilds.org/repository/14.1/multimedia/schroedinger/) |  |  |   
[video4linux](https://linuxtv.org/downloads/v4l-utils/) |  |  |   
  
## [[edit](https://en.cppreference.com/mwiki/index.php?title=c/links/libs&action=edit&section=9 "Edit section: Files")] Files

Library  |  Description  |  License  |  Configuration   
---|---|---|---  
[gmime](http://spruce.sourceforge.net/gmime/) |  |  |   
  
## [[edit](https://en.cppreference.com/mwiki/index.php?title=c/links/libs&action=edit&section=10 "Edit section: Maths")] Maths

Library  |  Description  |  License  |  Configuration   
---|---|---|---  
[gsl](https://www.gnu.org/software/gsl/) |  The GNU Scientific Library (GSL) is a numerical library for C and C++ ([Src](https://ftp.gnu.org/gnu/gsl/))  |  GPL  |  make   
  
Integer Multi-Dimensional Interpolation 
Library  |  Description  |  License  |  Configuration   
---|---|---|---  
[argyll](http://www.argyllcms.com/) |  |  |   
  
Linear algebra 
Library  |  Description  |  License  |  Configuration   
---|---|---|---  
[atlas](http://math-atlas.sourceforge.net/) |  |  |   
[blas](https://www.netlib.org/blas/) |  |  |   
[eigen](http://eigen.tuxfamily.org/index.php) |  |  |   
  
Finance 
Library  |  Description  |  License  |  Configuration   
---|---|---|---  
[ta-lib](https://sourceforge.net/projects/ta-lib/) |  |  |   
  
FFT 
Library  |  Description  |  License  |  Configuration   
---|---|---|---  
[fftw3](http://fftw.org) |  |  |   
  
Multiprecision 
Library  |  Description  |  License  |  Configuration   
---|---|---|---  
[gmp](https://gmplib.org/) |  |  |   
  
Signal Processing 
Library  |  Description  |  License  |  Configuration   
---|---|---|---  
[liquid-dsp](https://liquidsdr.org/) |  |  |   
[vsipl](https://www.omg.org/spec/VSIPL) |  |  |   
[vsipl++](https://www.omg.org/spec/VSIPL++) |  |  |   
  
## [[edit](https://en.cppreference.com/mwiki/index.php?title=c/links/libs&action=edit&section=11 "Edit section: Graphics")] Graphics

Library  |  Description  |  License  |  Configuration   
---|---|---|---  
[allegro](https://liballeg.org/index.html) |  Allegro-5 is a cross-platform multimedia library mainly aimed at video game and multimedia programming.  |  |   
[babl](http://gegl.org/babl/) |  |  |   
[Bgfx](https://github.com/bkaradzic/bgfx) |  A cross-platform, graphics API agnostic, "Bring Your Own Engine/Framework" style rendering library.  |  BSD 2  |   
[cairo](https://www.cairographics.org/) |  |  |   
[raylib](https://www.raylib.com/) |  A cross-platform C99 gamedev library featuring OpenGL hardware acceleration, full 3D support, skeletal animation, shaders, fonts, audio, math, GUI, etc. ([Src](https://github.com/raysan5/raylib)) ([Doc](https://github.com/raysan5/raylib/wiki/))  |  Zlib  |  cmake, make, vcpkg, zig   
[SAIL](https://sail.software) |  **S** quirrel **A** bstract **I** mage **L** ibrary is a small, fast, and cross-platform image decoding library.  |  |   
[SDL](https://libsdl.org/) |  **S** imple **D** irectMedia **L** ayer is a cross-platform library for input, audio, drawing and much more.  |  |   
[SIGIL](http://www.libsigil.com) |  |  |   
[Simple2d](https://github.com/simple2d/simple2d) |  A small, simple, cross-platform SDL2/OpenGL wrapper that provides drawing, media, windowing, and input capabilities.  |  MIT  |   
  
## [[edit](https://en.cppreference.com/mwiki/index.php?title=c/links/libs&action=edit&section=12 "Edit section: Generic")] Generic

Library  |  Description  |  License  |  Configuration   
---|---|---|---  
[libmixf](https://www.roberto-mameli.it/software/#libmixf) |  |  |   
  
## [[edit](https://en.cppreference.com/mwiki/index.php?title=c/links/libs&action=edit&section=13 "Edit section: Interprocess")] Interprocess

Library  |  Description  |  License  |  Configuration   
---|---|---|---  
[dbus](https://www.freedesktop.org/wiki/Software/dbus/) |  |  |   
[dee](https://launchpad.net/dee/) |  |  |   
[gdbus](https://www.freedesktop.org/wiki/Software/DBusBindings/) |  |  |   
  
## [[edit](https://en.cppreference.com/mwiki/index.php?title=c/links/libs&action=edit&section=14 "Edit section: Databases")] Databases

Library  |  Description  |  License  |  Configuration   
---|---|---|---  
[berkeley_db](https://www.oracle.com/database/technologies/related/berkeleydb.html) |  |  |   
[libfmrt](https://www.roberto-mameli.it/software/#libfmrt) |  |  |   
[libmongoc](https://github.com/mongodb/mongo-c-driver) |  Official C driver library for MongoDB ([Doc](https://www.mongodb.com/docs/drivers/c)). It offers optimized APIs for CRUD operations, comprehensive feature support (including [BSON](https://en.wikipedia.org/wiki/BSON "enwiki:BSON")) and support for different authentication mechanisms enabling efficient integration of MongoDB functionality into C-based applications.  |  Apache 2.0  |  CMake   
[lmdb](https://symas.com/lmdb/technical/) |  |  |   
[SQLite](https://sqlite.org/index.html) |  A C library that implements a small, fast, self-contained, high-reliability, full-featured, SQL database engine. SQLite is the most used database engine in the world. ([Src](https://sqlite.org/src)) ([Doc](https://sqlite.org/docs.html))  |  [Public Domain](https://sqlite.org/copyright.html) |   
  
## [[edit](https://en.cppreference.com/mwiki/index.php?title=c/links/libs&action=edit&section=15 "Edit section: Configuration")] Configuration

Library  |  Description  |  License  |  Configuration   
---|---|---|---  
[libconfig](https://hyperrealm.github.io/libconfig) |  |  |   
[libconfini](https://madmurphy.github.io/libconfini/html/index.html) |  |  |   
  
## [[edit](https://en.cppreference.com/mwiki/index.php?title=c/links/libs&action=edit&section=16 "Edit section: Environment")] Environment

Library  |  Description  |  License  |  Configuration   
---|---|---|---  
[libXDGdirs](https://github.com/Jorengarenar/libXDGdirs) |  |  |   
  
## [[edit](https://en.cppreference.com/mwiki/index.php?title=c/links/libs&action=edit&section=17 "Edit section: Communications")] Communications

Library  |  Description  |  License  |  Configuration   
---|---|---|---  
[gsoap](https://www.genivia.com/dev.html) |  |  |   
[KCP](https://github.com/skywind3000/kcp/blob/master/README.en.md) |  A fast and reliable ARQ protocol that helps applications to reduce network latency.  |  MIT  |   
[libcurl](https://curl.haxx.se/libcurl/) |  |  |   
[libmicrohttpd](https://www.gnu.org/software/libmicrohttpd/) |  |  |   
[libsagui](https://risoflora.github.io/libsagui/) |  |  |   
[MQTT-C](https://liambindle.ca/MQTT-C/) |  [Github URL](https://github.com/LiamBindle/MQTT-C) |  MIT  |   
[nanomsg](https://nanomsg.org/) |  A socket library that provides common communication patterns; has no dependencies; cross-platform. Superceded by the [nng](https://github.com/nanomsg/nng).  |  MIT/X11  |   
[UCX](https://github.com/openucx/ucx) |  Unified Communication X (UCX) provides an optimized communication layer for Message Passing (MPI), Shared Memory (PGAS) and RPC/data-centric applications.  |  BSD3  |   
[zeromq](https://zeromq.org/) |  |  |   
[libusb](https://libusb.info/) |  A portable C library that provides generic access to USB devices.  |  |   
  
## [[edit](https://en.cppreference.com/mwiki/index.php?title=c/links/libs&action=edit&section=18 "Edit section: Compression")] Compression

Library  |  Description  |  License  |  Configuration   
---|---|---|---  
[bzip2](http://www.bzip.org/) |  |  |   
[lz4](https://github.com/lz4/lz4) |  |  |   
[zlib](http://zlib.net/) |  |  |   
  
## [[edit](https://en.cppreference.com/mwiki/index.php?title=c/links/libs&action=edit&section=19 "Edit section: Concurrency")] Concurrency

Library  |  Description  |  License  |  Configuration   
---|---|---|---  
[ck](http://www.concurrencykit.org/) |  |  |   
[MutexGear](https://github.com/oleh-derevenko/mutexgear) |  Mutex-only synchronization (wheel, rwlock, work queues).  |  The MutexGear Library  |   
  
## [[edit](https://en.cppreference.com/mwiki/index.php?title=c/links/libs&action=edit&section=20 "Edit section: Data types")] Data types

Library  |  Description  |  License  |  Configuration   
---|---|---|---  
[bstrlib](http://bstring.sourceforge.net/) |  |  |   
[datastd](https://github.com/delphifeel/datastd) |  |  |   
[str](https://github.com/maxim2266/str) |  Yet another string library for C language.  |  |   
  
## [[edit](https://en.cppreference.com/mwiki/index.php?title=c/links/libs&action=edit&section=21 "Edit section: PDF")] PDF

Library  |  Description  |  License  |  Configuration   
---|---|---|---  
[PDFio](https://github.com/michaelrsweet/pdfio) |  A simple C library for reading and writing PDF files.  |  Apache-2.0  |  make   
  
## [[edit](https://en.cppreference.com/mwiki/index.php?title=c/links/libs&action=edit&section=22 "Edit section: XML")] XML

Library  |  Description  |  License  |  Configuration   
---|---|---|---  
[expat](http://expat.sourceforge.net) |  |  |   
[gsoap](http://gsoap2.sourceforge.net) |  |  |   
  
## [[edit](https://en.cppreference.com/mwiki/index.php?title=c/links/libs&action=edit&section=23 "Edit section: Metrics")] Metrics

Library  |  Description  |  License  |  Configuration   
---|---|---|---  
[edlib](http://github.com/martinsos/edlib) |  |  |   
  
## [[edit](https://en.cppreference.com/mwiki/index.php?title=c/links/libs&action=edit&section=24 "Edit section: Object oriented programming")] Object oriented programming

Library  |  Description  |  License  |  Configuration   
---|---|---|---  
[Cello](http://libcello.org/) |  |  |   
[GObject](https://docs.gtk.org/gobject/) |  |  |   
  
## [[edit](https://en.cppreference.com/mwiki/index.php?title=c/links/libs&action=edit&section=25 "Edit section: Web Frontend")] Web Frontend

Library  |  Description  |  License  |  Configuration   
---|---|---|---  
[cgit](http://git.zx2c4.com/cgit/about/) |  |  |   
  
## [[edit](https://en.cppreference.com/mwiki/index.php?title=c/links/libs&action=edit&section=26 "Edit section: Debug")] Debug

Library  |  Description  |  License  |  Configuration   
---|---|---|---  
[dbg-macro](https://github.com/eerimoq/dbg-macro) |  A few macros that print and return the value of a given expression for quick and dirty debugging, inspired by Rust’s dbg!(...) macro and its C++ variant.  |  MIT  |   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/links/libs&action=edit&section=27 "Edit section: See also")] See also

[C++ documentation](../../cpp/links/libs.html "cpp/links/libs") for Non-ANSI/ISO Libraries  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/links/libs&action=edit&section=28 "Edit section: External links")] External links

1\.  | [A list of C unit testing frameworks](https://en.wikipedia.org/wiki/List_of_unit_testing_frameworks#C "enwiki:List of unit testing frameworks") — at Wikipedia   
---|---  
2\.  | [A curated list of (awesome) C and C++ libraries](https://github.com/fffaraz/awesome-cpp) — at GitHub   
3\.  | [A list of C open-source games and frameworks](https://trilarion.github.io/opensourcegames/games/languages.html#c) — at GitHub.io   
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/links/libs&oldid=180169](https://en.cppreference.com/mwiki/index.php?title=c/links/libs&oldid=180169)" 
