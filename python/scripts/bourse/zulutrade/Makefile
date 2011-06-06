PYTHON=python
#PYTHON=python3 # because of euro symbol

all:
	$(MAKE) MyHistory
	#$(PYTHON) ZuluTradeMyHistory.py > out.txt
	#less out.txt

.PHONY: clean

MyHistory:
	$(PYTHON) cleanup.py ZuluTradeMyHistory.html > out.html
	$(PYTHON) html2csv.py out.html

	#$(PYTHON) ZuluTradeMyHistory.py
	
clean:
	$(RM) out.txt