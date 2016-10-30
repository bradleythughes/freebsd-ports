# $FreeBSD$
#
# Provide support for Node.js
#
# Feature:      node
# Usage:        USES=node, or USES=node:args
# Valid ARGS:   <version>, build, run, test
#
# version	The major version of Node.js required by your port. If omitted,
#		the default version is used. The user can choose which Node.js
#		version to use as the default using:
#
# DEFAULT_VERSIONS+=	node=<major version>
#
# build		Indicates that Node.js is needed at build time and adds
#		it to BUILD_DEPENDS.
# run		Indicates that Node.js is needed at run time and adds
#		it to RUN_DEPENDS.
# test		Indicates that Node.js is needed at test time and adds
#		it to TEST_DEPENDS.
#
# If build, run and test are omitted, Node.js will be added as BUILD_DEPENDS,
# RUN_DEPENDS and TEST_DEPENDS.
#
# MAINTAINER:	bhughes@FreeBSD.org

.if !defined(_INCLUDE_USES_NODE_MK)
_INCLUDE_USES_NODE_MK=    yes


# Please keep this list sorted by ascending major version number. Be sure to
# update the comment in Mk/bsd.default-versions.mk when changing this list.
_NODE_MAJOR_VERSIONS=	4 6 8 9

.if ${node_ARGS:N[4689]:Nbuild:Nrun:Ntest}
IGNORE?=        Unknown USES=node argument ${node_ARGS}
.endif

.if ${NODE_DEFAULT:N[4689]}
IGNORE?=        Invalid NODE_DEFAULT value: ${NODE_DEFAULT}, please select one of ${_NODE_MAJOR_VERSIONS}
.endif


# Make sure that no dependency or some other environment variable
# pollutes the build/run dependency detection
.undef _NODE_BUILD_DEP
.undef _NODE_RUN_DEP
.undef _NODE_TEST_DEP
_NODE_ARGS=           ${node_ARGS:S/,/ /g}
.if ${_NODE_ARGS:Mbuild}
_NODE_BUILD_DEP=      yes
_NODE_ARGS:=          ${_NODE_ARGS:Nbuild}
.endif
.if ${_NODE_ARGS:Mrun}
_NODE_RUN_DEP=        yes
_NODE_ARGS:=          ${_NODE_ARGS:Nrun}
.endif
.if ${_NODE_ARGS:Mtest}
_NODE_TEST_DEP=       yes
_NODE_ARGS:=          ${_NODE_ARGS:Ntest}
.endif

# The port does not specify a build, run or test dependency, assume all are
# required.
.if !defined(_NODE_BUILD_DEP) && !defined(_NODE_RUN_DEP) && \
    !defined(_NODE_TEST_DEP) && !defined(NODE_NO_DEPENDS)
_NODE_BUILD_DEP=      yes
_NODE_RUN_DEP=        yes
_NODE_TEST_DEP=       yes
.endif


# The remaining argument, if any, is the Node.js major version to use.
_NODE_VERSION=	${_NODE_ARGS:S/.//g}
.if empty(_NODE_VERSION)
_NODE_VERSION=	${NODE_DEFAULT}
.endif
.if ${_NODE_VERSION} == ${_NODE_MAJOR_VERSIONS:[-1]}
# The latest major version always lives in www/node
_NODE_PORT=	node:www/node
.else
_NODE_PORT=	node:www/node${_NODE_VERSION}
.endif


# Add build, run, and test dependencies as required.
.if defined(_NODE_BUILD_DEP)
BUILD_DEPENDS+=	${_NODE_PORT}
.endif
.if defined(_NODE_RUN_DEP)
RUN_DEPENDS+=	${_NODE_PORT}
.endif
.if defined(_NODE_TEST_DEP)
TEST_DEPENDS+=	${_NODE_PORT}
.endif


.endif # _INCLUDE_USES_NODE_MK
