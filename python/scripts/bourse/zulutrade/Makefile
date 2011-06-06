PYTHON=python
#PYTHON=python3 # because of euro symbol

all:
	$(MAKE) MyHistory

.PHONY: clean

MyHistory:
	$(PYTHON) cleanup.py ZuluTradeMyHistory.html > out.html
	$(PYTHON) html2csv.py out.html

	#$(PYTHON) ZuluTradeMyHistory.py out.csv
	
clean:
	$(RM) out.txt