all:
	python main.py
	convert -delay 9 -loop 0 logo_*.gif animated.gif # ImageMagick

.PHONY: clean

clean:
	$(RM) logo_*.gif