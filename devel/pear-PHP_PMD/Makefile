# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	PHP_PMD
PORTVERSION=	1.5.0
CATEGORIES=	devel pear
MASTER_SITES=	http://pear.phpmd.org/get/
PKGNAMEPREFIX=	pear-

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	PHP Mess Detector

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PEARDIR}/.channels/pear.phpmd.org.reg:devel/pear-channel-phpmd
RUN_DEPENDS=	${PEARDIR}/.channels/pear.phpmd.org.reg:devel/pear-channel-phpmd

PORTSCOUT=	skipv=2.*

USES=	pear
PEAR_CHANNEL=	phpmd
USE_PHP=	dom simplexml
NO_ARCH=	yes

.include <bsd.port.mk>
