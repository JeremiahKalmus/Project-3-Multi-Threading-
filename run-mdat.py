#!/usr/bin/python

import os
import sys
import math
from optparse import OptionParser

parser = OptionParser("%prog -R <runs> -t <threads> -r <rounds> -m <mode (1 or 2)> [-c]")
parser.add_option("-R", "--runs", dest = "numRuns", type = "int", help = "number of test runs")
parser.add_option("-t", "--threads", dest = "numThreads", type = "int", help = "number of threads")
parser.add_option("-r", "--rounds", dest = "numRounds", type = "int", help = "number of rounds per run")
parser.add_option("-m", "--mode", dest = "mode", type = "string", help = "mode (1 or 2)")
parser.add_option("-c", "--continue", dest = "continuePastError", action = "store_true",
  default = False, help = "continue past error")

(opts, args) = parser.parse_args()

# Set local variables
numRuns = opts.numRuns
numThreads = opts.numThreads
numRounds = opts.numRounds
mode = opts.mode
continuePastError = opts.continuePastError

if numRuns < 1:
  parser.error("Number of test runs must be greater than 0.  Found:  " + str(numRuns))

if numThreads < 1:
  parser.error("Number of threads must be greater than 0.  Found:  " + str(numThreads))

if numRounds < 1:
  parser.error("Number of rounds must be greater than 0.  Found:  " + str(numRounds))

if mode != "1" and mode != "2":
  parser.error("Mode is required to be either 1 or 2.")

# Build command line
if mode == "1":
  cmdLine = "./mdat1 "
else:
  cmdLine = "./mdat2 "
cmdLine += "-t " + str(numThreads) + " -r " + str(numRounds) + " -o trace.mdat"
print "--------------------------------------------------------------------"
print "MDAT command line:"
print cmdLine
print "--------------------------------------------------------------------"

# Run tests for numRuns iterations
if continuePastError:
  testPass = 0 
  testFail = 0 
  for i in xrange(1, numRuns+1):
    if os.system(cmdLine):
      testFail += 1
      print "Run " + str(i) + " FAILED"
    else:
      testPass += 1
      print "Run " + str(i) + " passed"

  print "Tests passed: " + str(testPass) + " Tests failed: " + str(testFail)
  os.system("rm -f trace.mdat")

else:
  sys.stdout.write("Run ")
  for i in xrange(1, numRuns+1):
    if i == 1:
      numBackspace = 0
    else:
      numBackspace = int(math.log10(i - 1)) + 1 
    for j in xrange(1, numBackspace + 1):
      sys.stdout.write("\b")
    sys.stdout.write(str(i))
    sys.stdout.flush()
    if os.system(cmdLine):
      print "\nFAIL: Test execution failed during run " + str(i) + "."
      print "Trace is located in trace.mdat"
      sys.exit(-1)
  print "\nAll tests PASSED"
  os.system("rm -f trace.mdat")

# Successful exit
sys.exit(0)
