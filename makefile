JFLAGS = -g --release 10
JC = javac
JVM = java 
MAIN = Pegame/Main
.SUFFIXES: .java .class
.java.class:
		$(JC) $(JFLAGS) $*.java

CLASSES = \
        Pegame/Pegame.java \
        Pegame/Main.java 

default: classes

classes: $(CLASSES:.java=.class)

run: classes
		$(JVM) $(MAIN)

clean:
		$(RM) Pegame/*.class