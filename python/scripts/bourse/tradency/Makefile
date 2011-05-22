PYTHON = python3

all:
	$(MAKE) perf > Out_Performance.txt
	
perf:
	$(PYTHON) TradencyPerformance.py
	
myhist:
	$(PYTHON) TradencyMyHistory.py

.PHONY: clean

clean:
	$(RM) Out_*.txt