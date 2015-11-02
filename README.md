# MBCode
Repository containing code for pulling the MB bits from data and performing matching between emulation and data

Before running the analyzer you must run reco_RAW2DIGI.py the RAW->DIGI step on the RAW data in order to gain access to the HFDigis and the HcalTrigPrimDigis.

Once you have the RAWDIGI output then run the analyzer on this input to pull the MB bit decisions.

If you want you can run the MBMacthing code to compare the MB bit decisions in data and emulation. It reads the tree that is output from the L1+HLT emulation and the tree output from the above analyzer. 
