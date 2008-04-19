#!/usr/bin/env python

import smtplib

smtpserver = 'mail.example.com'
AUTHREQUIRED = 0 # if you need to use SMTP AUTH set to 1
smtpuser = ''  # for SMTP AUTH, set SMTP username here
smtppass = ''  # for SMTP AUTH, set SMTP password here

RECIPIENTS = ['user@example.com']
SENDER = 'jimbob@example.net'
mssg = open('mssg.txt', 'r').read()

session = smtplib.SMTP(smtpserver)
if AUTHREQUIRED:
    session.login(smtpuser, smtppass)
smtpresult = session.sendmail(SENDER, RECIPIENTS, mssg)

if smtpresult:
    errstr = ""
    for recip in smtpresult.keys():
        errstr = """Could not delivery mail to: %s

Server said: %s
%s

%s""" % (recip, smtpresult[recip][0], smtpresult[recip][1], errstr)
    raise smtplib.SMTPException, errstr
