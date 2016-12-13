# Dotlinker
## _A C++ implementation_

A while back I implemented this little program in Ruby. It works great. On my laptop. Not so much when I tried to bring it to Raspbery Pis, where Ruby isn't even installed by default.

So what's the solution? ~~Write in the Pi's native language, Python!~~ Use modern C++ that isn't even supported by the compilers on my target platform yet, so I have to compile ahead of time and statically link the libraries in! And even then it segfaults! this is a pointless project. I'm so sorry.
