/*
  This file is part of the Grantlee template system.

  Copyright (c) 2009 Stephen Kelly <steveire@gmail.com>

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License version 3 only, as published by the Free Software Foundation.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License version 3 for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library.  If not, see <http://www.gnu.org/licenses/>.

*/

#ifndef DEFAULTFILTERS_H
#define DEFAULTFILTERS_H

#include "node.h"
#include "filter.h"
#include "interfaces/taglibraryinterface.h"

#include "upper.h"
#include "lower.h"
#include "yesno.h"
#include "truncatewords.h"
#include "join.h"
#include "removetags.h"
#include "default_if_none.h"
#include "cut.h"
#include "slice.h"
#include "safe.h"

#include "grantlee_export.h"

namespace Grantlee
{
class Parser;
}

using namespace Grantlee;

class DefaultFiltersLibrary : public QObject, public TagLibraryInterface
{
  Q_OBJECT
  Q_INTERFACES( Grantlee::TagLibraryInterface )
public:
  DefaultFiltersLibrary( QObject *parent = 0 )
      : QObject( parent ) {
    m_filters.insert( "upper", new UpperFilter() );
    m_filters.insert( "lower", new LowerFilter() );
    m_filters.insert( "yesno", new YesNoFilter() );
    m_filters.insert( "truncatewords", new TruncateWordsFilter() );
    m_filters.insert( "join", new JoinFilter() );
    m_filters.insert( "removetags", new RemoveTagsFilter() );
    m_filters.insert( "default_if_none", new DefaultIfNoneFilter() );
    m_filters.insert( "cut", new CutFilter() );
    m_filters.insert( "slice", new SliceFilter() );
    m_filters.insert( "safe", new SafeFilter() );
  }

  virtual QHash<QString, Filter*> filters( const QString &name = QString() ) {
    Q_UNUSED( name );
    return m_filters;
  }

private:
  QHash<QString, Filter*> m_filters;

};

#endif

