/******************************************************************************
 * Icinga 2                                                                   *
 * Copyright (C) 2012-2015 Icinga Development Team (http://www.icinga.org)    *
 *                                                                            *
 * This program is free software; you can redistribute it and/or              *
 * modify it under the terms of the GNU General Public License                *
 * as published by the Free Software Foundation; either version 2             *
 * of the License, or (at your option) any later version.                     *
 *                                                                            *
 * This program is distributed in the hope that it will be useful,            *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              *
 * GNU General Public License for more details.                               *
 *                                                                            *
 * You should have received a copy of the GNU General Public License          *
 * along with this program; if not, write to the Free Software Foundation     *
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.             *
 ******************************************************************************/

#ifndef CONFIGWRITER_H
#define CONFIGWRITER_H

#include "config/i2-config.hpp"
#include "base/object.hpp"
#include "base/array.hpp"
#include "base/dictionary.hpp"
#include <fstream>

namespace icinga
{

/**
 * A configuration writer.
 *
 * @ingroup config
 */
class I2_CONFIG_API ConfigWriter
{
public:
	static void EmitBoolean(std::ostream& fp, bool val);
	static void EmitNumber(std::ostream& fp, double val);
	static void EmitString(std::ostream& fp, const String& val);
	static void EmitEmpty(std::ostream& fp);
	static void EmitArray(std::ostream& fp, const Array::Ptr& val);
	static void EmitArrayItems(std::ostream& fp, const Array::Ptr& val);
	static void EmitDictionary(std::ostream& fp, const Dictionary::Ptr& val);
	static void EmitScope(std::ostream& fp, int indentLevel, const Dictionary::Ptr& val, const Array::Ptr& imports = Array::Ptr());
	static void EmitValue(std::ostream& fp, int indentLevel, const Value& val);
	static void EmitRaw(std::ostream& fp, const String& val);
	static void EmitIndent(std::ostream& fp, int indentLevel);

	static void EmitIdentifier(std::ostream& fp, const String& identifier, bool inAssignment);
	static void EmitConfigItem(std::ostream& fp, const String& type, const String& name, bool isTemplate,
	    const Array::Ptr& imports, const Dictionary::Ptr& attrs);

	static void EmitComment(std::ostream& fp, const String& text);
	static void EmitFunctionCall(std::ostream& fp, const String& name, const Array::Ptr& arguments);

private:
	ConfigWriter(void);

	static String EscapeIcingaString(const String& str);
};

}

#endif /* CONFIGWRITER_H */
