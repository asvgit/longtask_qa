MGR = billmgr
PLUGIN = longtask_qa
VERSION = 0.1
LIB += longtask_qa
longtask_qa_SOURCES = longtask_qa.cpp

BASE ?= /usr/local/mgr5
include $(BASE)/src/isp.mk
