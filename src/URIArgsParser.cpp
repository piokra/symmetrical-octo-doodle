//
// Created by panpiotr on 05.08.17.
//

#include <iostream>
#include "ERF/URIArgsParser.h"

using namespace Poco;

URIArgsParser::URIArgsParser(const std::string &pattern) : _regex(patternize(pattern)) {

}

std::unordered_map<std::string, std::string> URIArgsParser::parse(const std::string &uri) const {

    std::unordered_map<std::string, std::string> ret;

    RegularExpression::MatchVec matchVec;

    _regex.match(uri, 0, matchVec);

    for (size_t i = 1; i < std::min(matchVec.size(), _argNames.size()) + 1; ++i) {
        ret[_argNames[i - 1]] = uri.substr(matchVec[i].offset, matchVec[i].length);
    }

    return ret;
}

std::string URIArgsParser::patternize(const std::string &pattern) {
    auto copy = pattern;
    RegularExpression regularExpression("{\\w*}");
    RegularExpression nameRE("{(\\w*)}");

    RegularExpression::Match match;
    match.offset = 0;
    match.length = 0;

    while (true) {
        nameRE.match(pattern, match.offset + match.length, match);
        if (match.offset == std::string::npos) {
            break;
        }
        _argNames.push_back(pattern.substr(match.offset+1, match.length-2));

    }
    regularExpression.subst(copy, "(\\w*)", RegularExpression::RE_GLOBAL);
    copy = "^/?" + copy;
    copy += "/?$";
    return copy;
}

bool URIArgsParser::matches(const std::string &uri) const {
    return _regex.match(uri, 0);
}
