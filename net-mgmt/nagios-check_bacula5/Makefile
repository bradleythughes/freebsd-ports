# Created by: Anders Troback
# $FreeBSD$

PORTNAME=	bacula
CATEGORIES=	net-mgmt
PKGNAMEPREFIX=	nagios-check_
PKGNAMESUFFIX=	5

MAINTAINER=	freebsd@troback.com
COMMENT=	Nagios plugin for Bacula

LIB_DEPENDS+=	libbac.so:sysutils/bacula5-client

PLIST=		${.CURDIR}/pkg-plist
PLIST_FILES=	libexec/nagios/check_bacula
WITH_NAGIOS_CHECK_ONLY=	yes
MASTERDIR=	${.CURDIR}/../../sysutils/bacula5-server

CONFIGURE_ARGS=	--enable-client-only	\
		--disable-build-dird	\
		--disable-build-stored	\
		--disable-nls		\
		--disable-xatt

OPTIONS_DEFINE=	#

.include "${MASTERDIR}/Makefile"
