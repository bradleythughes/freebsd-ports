# Created by: Sergey Kozlov <kozlov.sergey.404@gmail.com>
# $FreeBSD$

PORTNAME=	kibana
PORTVERSION=	4.1.11
DISTVERSIONSUFFIX=	-linux-x86
CATEGORIES=	textproc www
MASTER_SITES=	http://download.elastic.co/kibana/kibana/
PKGNAMESUFFIX=	41

MAINTAINER=	kozlov.sergey.404@gmail.com
COMMENT=	Browser based analytics and search interface to ElasticSearch

LICENSE=	APACHE20

USES=		node:4,run

NO_BUILD=	yes
NO_ARCH=	yes
WWWDIR=		${PREFIX}/www/${PORTNAME}${PKGNAMESUFFIX}
USE_RC_SUBR=	${PORTNAME}

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	@cd ${WRKSRC}/src && \
		${RM} config/kibana.yml bin/kibana.sh bin/kibana.bat && \
		${RM} -r node_modules/bunyan/node_modules/dtrace-provider && \
		${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}
	@${CP} ${WRKSRC}/config/kibana.yml ${STAGEDIR}${PREFIX}/etc/kibana.yml.sample

.include <bsd.port.mk>
