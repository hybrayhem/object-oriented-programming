JFLAGS = -g --release 10
JC = javac
JVM = java 
MAIN = DateTime/Main
.SUFFIXES: .java .class
.java.class:
		$(JC) $(JFLAGS) $*.java

CLASSES = \
        DateTime/DayOfYearSet.java \
        DateTime/Main.java 

default: classes

classes: $(CLASSES:.java=.class)

run: classes
		$(JVM) $(MAIN)

clean:
		$(RM) DateTime/*.class