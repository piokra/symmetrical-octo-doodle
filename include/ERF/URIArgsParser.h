//
// Created by panpiotr on 05.08.17.
//

#ifndef ERF_URIARGSPARSER_H
#define ERF_URIARGSPARSER_H

#include <vector>
#include <string>

#include <Poco/RegularExpression.h>
#include <unordered_map>

class URIArgsParser {
public:
    URIArgsParser(const std::string &pattern);

    std::unordered_map<std::string, std::string> parse(const std::string &uri) const;

    bool matches(const std::string &uri) const;

protected:
    std::string patternize(const std::string &pattern);

private:
    std::vector<std::string> _argNames;
    Poco::RegularExpression _regex;

};


#endif //ERF_URIARGSPARSER_H
