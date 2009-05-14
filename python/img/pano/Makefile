all:
	$(MAKE) clean
	python main.py
	convert -delay 100 -loop 0 temp_*.gif animated.gif # ImageMagick

.PHONY: clean

clean:
	$(RM) temp_*.gif