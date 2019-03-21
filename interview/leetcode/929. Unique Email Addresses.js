/**
 * @param {string[]} emails
 * @return {number}
 */
var numUniqueEmails = function(emails) {
  // 格式化email
  function format(email) {
    // 匹配 本地
    let localMatch = email.match(/^[^+]*/)[0];
    let localStr = localMatch.split(".").join("");
    // 匹配 域名
    let domainMatch = email.match(/\@.*$/)[0];
    return localStr + domainMatch;
  }

  const emailsMap = {};
  emails.forEach(email => (emailsMap[format(email)] = 1));
  console.log(emailsMap)
  return Object.keys(emailsMap).length;
};

console.log(
  numUniqueEmails([
    "test.email+alex@leetcode.com",
    "test.e.mail+bob.cathy@leetcode.com",
    "testemail+david@lee.tcode.com"
  ]),
  numUniqueEmails([
    "testemail@leetcode.com",
    "testemail1@leetcode.com",
    "testemail+david@lee.tcode.com"
  ])
);
