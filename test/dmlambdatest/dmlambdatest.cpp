#include <iostream>
#include <typeinfo>

#include <tuple>
#include <type_traits>
#include "dmformat.h"
#include "dmnameof.h"

namespace stx
{

    namespace lambda_detail
    {
        // ���Ƿ�is_mutable���������͡���������Ԫ�ظ���������������ȡ����
        template<class Ret, class Cls, class IsMutable, class... Args>
        struct types
        {
            using is_mutable = IsMutable;

            enum { arity = sizeof...(Args) };

            using return_type = Ret;

            template<size_t i>
            struct arg
            {
                typedef typename std::tuple_element<i, std::tuple<Args...>>::type type;
            };
        };
    }

    // ģ�����LambdaType��lambda���ʽ�����ͣ��Ƕ�����������
    // ���ñ������Զ��Ƶ�������ʹ��decltype(lamdba)�Ƶ�
    // &T::operator()���ָ�����Ա������ָ��
    // decltype�Ƶ��õ�lambda���ʽ�ĺ���ǩ��
    // ���ü̳У���ʵ����lambda_type<LambdaType>ʱ��
    // ͨ��decltype�Ƶ�����ǩ�����Ӷ�ʵ�������������ػ��汾�е�һ��
    template<class LambdaType>
    struct lambda_type
        : lambda_type<decltype(&LambdaType::operator())>
    {};

    // �ػ��汾������Ϊ��const����Ӧ��lambda���ʽΪmutable��
    template<class Ret, class Cls, class... Args>
    struct lambda_type<Ret(Cls::*)(Args...)>
        : lambda_detail::types<Ret, Cls, std::true_type, Args...>
    {};

    // �ػ��汾������Ϊconst
    template<class Ret, class Cls, class... Args>
    struct lambda_type<Ret(Cls::*)(Args...) const>
        : lambda_detail::types<Ret, Cls, std::false_type, Args...>
    {};

};
class lam
{
public:
    std::string name;
    int age;
};
int main(void){

    fmt::print("[is mutable lambda]\n");
    {
        auto test = [](int a) mutable->long{return static_cast<long>(a); };
        fmt::print("ret type : {}\n", std::is_same<stx::lambda_type<decltype(test)>::return_type, long>::value);
        fmt::print("arg size : {}\n", stx::lambda_type<decltype(test)>::arity);

        fmt::print("arg {} type : {}\n", 0, std::is_same<stx::lambda_type<decltype(test)>::arg<0>::type, int>::value);

        fmt::print("is mutable : {}\n", std::is_same<stx::lambda_type<decltype(test)>::is_mutable, std::true_type>::value);
    }
    int b = 0;

    fmt::print("[is normal lambda]\n");
    {
        auto test = [b](int a, int b)->long{return static_cast<long>(a); };

        fmt::print("NAMEOF_FULL: {} {}\n", NAMEOF_FULL(&test), NAMEOF_FULL_TYPE_EXPR(test));
        fmt::print("ret type : {}\n", std::is_same<stx::lambda_type<decltype(test)>::return_type, long>::value);
        fmt::print("arg size : {}\n", stx::lambda_type<decltype(test)>::arity);

        fmt::print("arg {} type : {}\n", 0, std::is_same<stx::lambda_type<decltype(test)>::arg<0>::type, int>::value);
        fmt::print("arg {} type : {}\n", 1, std::is_same<stx::lambda_type<decltype(test)>::arg<1>::type, int>::value);

        fmt::print("is mutable : {}\n", std::is_same<stx::lambda_type<decltype(test)>::is_mutable, std::true_type>::value);
    }

    fmt::print("[is class]\n");
    {
        fmt::print("{}\n{}\n{}\n", NAMEOF_TYPE_EXPR(std::declval<lam>()), NAMEOF_FULL_TYPE_EXPR(lam::name), NAMEOF_FULL_TYPE_EXPR(lam::age));
    }
}
