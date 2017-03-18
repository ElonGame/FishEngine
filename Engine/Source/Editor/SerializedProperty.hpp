#pragma once

#include "FishEditor.hpp"
#include "SerializedPropertyType.hpp"

namespace FishEditor
{
	class SerializedProperty
	{
	private:
		SerializedObjectPtr m_SerializedObject;
		SerializedProperty() = default;

	public:
		~SerializedProperty()
		{
			this->Dispose();
		}

		SerializedObjectPtr serializedObject() const
		{
			return m_SerializedObject;
		}

		bool hasMultipleDifferentValues() const;
		int hasMultipleDifferentValuesBitwise() const;
		std::string displayName() const;
		std::string name() const;
		std::string type() const;
		std::string tooltip() const;
		int depth() const;
		std::string propertyPath() const;
		bool editable() const;
		bool isAnimated() const;
		bool isExpanded() const;
		bool hasChildren() const;
		bool hasVisibleChildren() const;
		bool isInstantiatedPrefab() const;
		bool prefabOverride() const;
		SerializedPropertyType propertyType() const;

		int intValue();
		long longValue();
		bool boolValue();
		float floatValue();
		double doubleValue();
		std::string stringValue();
		FishEngine::Color colorValue();
		//AnimationCurve animationCurveValue();
		//Gradient gradientValue();
		FishEngine::ObjectPtr objectReferenceValue();
		int objectReferenceInstanceIDValue();
		std::string objectReferenceStringValue();
		std::string objectReferenceTypeString();
		std::string layerMaskStringValue();
		int enumValueIndex();
		std::vector<std::string> enumNames();
		std::vector<std::string> enumDisplayNames();
		FishEngine::Vector2 vector2Value();
		FishEngine::Vector3 vector3Value();
		FishEngine::Vector4 vector4Value();
		FishEngine::Quaternion quaternionValue();
		FishEngine::Rect rectValue();
		FishEngine::Bounds boundsValue();

		bool isArray();
		int arraySize();

		void Dispose();
		bool EqualContents(SerializedPropertyPtr x, SerializedPropertyPtr y);

		bool Next(bool enterChildren);
		bool NextVisible(bool enterChildren);
		void Reset();
		int CountRemaining();
		int CountInProperty();
		SerializedProperty Copy();

		bool DuplicateCommand();
		bool DeleteCommand();

		SerializedProperty FindPropertyRelative(std::string const &relativePropertyPath);
		SerializedProperty GetEndProperty();
		SerializedProperty GetEndProperty(bool includeInvisible = false);

	private:
		int hashCodeForPropertyPathWithoutArrayIndex() const;
		void SetBitAtIndexForAllTargetsImmediate(int index, bool value);
		bool ValidateObjectReferenceValue(FishEngine::ObjectPtr obj);
		void AppendFoldoutPPtrValue(FishEngine::ObjectPtr obj);

		SerializedProperty CopyInternal();
	};
}
