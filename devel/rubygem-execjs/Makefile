# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	execjs
PORTVERSION=	2.7.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	ExecJS lets you run JavaScript code from Ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

OPTIONS_SINGLE=	BACKEND
OPTIONS_SINGLE_BACKEND=	NODE NODE4 NODE6
OPTIONS_DEFAULT=	NODE

NODE_DESC=	Use www/node as backend
NODE4_DESC=	Use www/node4 as backend
NODE6_DESC=	Use www/node6 as backend

NODE_USES=	node:run
NODE4_USES=	node:4,run
NODE6_USES=	node:6,run

post-patch:
	@${REINPLACE_CMD} -e 's#%%LOCALBASE%%#${LOCALBASE}#' \
		${WRKSRC}/lib/${PORTNAME}/runtimes.rb

.include <bsd.port.mk>
